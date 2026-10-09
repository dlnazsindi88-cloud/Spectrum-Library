#include <iostream>
#include <string>
#include <vector>

// پێکهاتا یارییا etaHEN
struct EtaGame {
    std::string title;
        std::string pkgUrl; 
            std::string size;
            };

            // تابعا فرێکرنا داخوازیا داونلۆدکرنێ بۆ etaHEN Web API
            void installPkgToEtaHEN(const EtaGame& game) {
                std::cout << "\n[+] ناردنا داخوازیا داونلۆدکرنێ بۆ etaHEN..." << std::endl;
                    std::cout << "[+] ناڤێ یاریێ: " << game.title << std::endl;
                        std::cout << "[+] قەبارە: " << game.size << std::endl;
                            
                                // ناردنا فایلا .pkg ب ڕێیا etaHEN Web API (پۆرتا 9090)
                                    std::string command = "curl -X POST http://127.0.0.1:9090/status -d '{\"pkg_url\":\"" + game.pkgUrl + "\"}'";
                                        
                                            int result = system(command.c_str());
                                                
                                                    if(result == 0) {
                                                            std::cout << "[✓] یارییا " << game.title << " ب سەرکەفتن هاتە فرێکرن بۆ etaHEN داونلۆدەر!" << std::endl;
                                                                } else {
                                                                        std::cout << "[!] کێشەیەک پەیدا بوو د فرێکرنا داخوازیێ دا." << std::endl;
                                                                            }
                                                                            }

                                                                            int main() {
                                                                                // لیستا یاریێن دکانێ (Minecraft PPSA17221)
                                                                                    std::vector<EtaGame> etaStore = {
                                                                                            {"Minecraft PS5 (PPSA17221)", "https://www.mediafire.com/file/sgdve43b5n1w7yb/[DLPSGAME.COM]-PPSA17221.rar/file", "GB ?"}
                                                                                                };

                                                                                                    std::cout << "=== دکانا یاریێن etaHEN PKG Store ===" << std::endl;
                                                                                                        for (size_t i = 0; i < etaStore.size(); ++i) {
                                                                                                                std::cout << i + 1 << ". " << etaStore[i].title << " (" << etaStore[i].size << ")" << std::endl;
                                                                                                                    }

                                                                                                                        // هەڵبژارتنا یارییا ئێکێ (Minecraft)
                                                                                                                            int choice = 1;
                                                                                                                                std::cout << "\nتە یارییا ژمارە " << choice << " هەڵبژارت." << std::endl;
                                                                                                                                    
                                                                                                                                        installPkgToEtaHEN(etaStore[choice - 1]);

                                                                                                                                            return 0;
                                                                                                                                            }
                                                                                                                                            