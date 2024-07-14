#include <iostream>

class Television {
    public:
        int channel;
        int volume;
        bool on;

        Television() {
            channel = 1;    // Default channel is 1
            volume = 1;     // Default volume is 1
            on = false;     // By default, television is off
        }

        void turn_on() {
            on = true;
        }

        void turn_off() {
            on = false;
        }

        void set_channel (int new_channel) {
            if (on && new_channel >= 1 && new_channel <= 120) {
                channel = new_channel;
            }
        }

        void set_volume (int new_volume) {
            if (on && new_volume >= 1 && new_volume <= 7) {
                volume = new_volume;
            }
        }

        void channel_up() {
            if (on && channel < 120) {
                channel++;
            }
        }

        void channel_down() {
            if (on && channel > 1) {
                channel--;
            }
        }

        void volume_up() {
            if (on && volume < 7) {
                volume++;
            }
        }

        void volume_down() {
            if (on && volume > 1) {
                volume--;
            }
        }
};

int main() {
    Television television_1;

    television_1.turn_on();
    television_1.set_channel(30);
    television_1.set_volume(3);

    Television television_2;
    
    television_2.turn_on();
    television_2.channel_up();
    television_2.channel_up();
    television_2.volume_up();

    std::cout << "Television 1" << "\n";
    std::cout << television_1.channel << " " << television_1.volume << "\n";

    std::cout << "Television 2" << "\n";
    std::cout << television_2.channel << " " << television_2.volume << "\n";

    return 0;
}
