#include <iostream>
#include <queue>
int main() {
    std::queue<int> memory;

    // m为内存容量 n为需要翻译的总数
    int m,n;
    std::cin>>m>>n;

    //word为当前翻译的单词
    int word;

    int hashWord[10001] = {0};

    int count = 0;
    for(int i = 0; i<n;i++){
        std::cin>>word;
        if(hashWord[word]==0){
            hashWord[word] = 1;

            if(memory.size()<m){
                //std::cout<<"查找单词"<<word<<"并放入内存"<<std::endl;
                memory.push(word);
                count++;
            }else{
                //std::cout<<"查找单词"<<word<<"并放入内存,替代单词"<<memory.front()<<std::endl;
                hashWord[memory.front()] = 0;
                memory.pop();
                memory.push(word);
                count++;
                
            }
        }
        else
        {
            //std::cout<<"在内存中找到单词"<<word<<std::endl;
            continue;
        }
        
    }
    std::cout<<count<<std::endl;
}