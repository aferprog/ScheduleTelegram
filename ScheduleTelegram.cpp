#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <string>
#include <vector>

#include <tgbot/tgbot.h>

using namespace std;
using namespace TgBot;

class Record {
public:
    vector<string> messages;
    string responce;
    vector<string> tips;
    int tip_ind;
};

std::vector<Record> tasks;
int task_ind=0;

void init() {
    
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Тест";
    // string token(getenv("TOKEN"));
    string token = "1368992915:AAGQ_pMBwlWy7_HwKxpfAthFe9i78hKkI5Y";
    printf("Token: %s\n", token.c_str());

    Bot bot(token);

    init();

    pair<size_t, size_t> user = {0, 0};
    bot.getEvents().onCommand("start", [&bot, &user](Message::Ptr message) {
        if (user.first == 0) {
            

            user.first = message->chat->id;
            bot.getApi().sendMessage(message->chat->id, "Привет. Я тебя ждал", false, 0);
            bot.getApi().sendMessage(message->chat->id, "Меня зовут botik. А тебя я буду знать Олег", false, 0);
            bot.getApi().sendMessage(message->chat->id, "Я спрятал здесь ключ, Олег. ", false, 0);
            bot.getApi().sendMessage(message->chat->id, message->from->username, false, 0);
        }
               
    });

    bot.getEvents().onAnyMessage([&bot](Message::Ptr message) {
        printf("User wrote %s\n", message->text.c_str());
        if (StringTools::startsWith(message->text, "/start") || StringTools::startsWith(message->text, "/layout")) {
            return;
        }
        bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
        });

    signal(SIGINT, [](int s) {
        printf("SIGINT got\n");
        exit(0);
        });

    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        bot.getApi().deleteWebhook();

        TgLongPoll longPoll(bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    }
    catch (exception& e) {
        printf("error: %s\n", e.what());
    }

    return 0;
}