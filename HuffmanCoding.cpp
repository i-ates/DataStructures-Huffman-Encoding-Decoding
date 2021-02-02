//
// Created by Ates on 12/23/2020.
//

#include "HuffmanCoding.h"
#include <iostream>
#define COUNT 7
HuffmanCoding::HuffmanCoding() {

}
// traverse the Huffman Tree and decode the encoded string
Node *HuffmanCoding::getNode(char char1, int frequence, Node* left, Node* right)
{
    Node* node = new Node();

    node->char1 = char1;
    node->frequence = frequence;
    node->left = left;
    node->right = right;

    return node;
}
void HuffmanCoding::printList(Node *root1, int space) {
    if (root1 == NULL)
        return;

    space += COUNT;

    printList(root1->right, space);

    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<"_";
    if (root1->char1== NULL){
        cout<<"**"<<root1->frequence<<"\n";

    }else{
        cout<<root1->char1<<"->"<<root1->frequence<<"\n";

    }
    printList(root1->left, space);
}
void HuffmanCoding::encode(Node* root, string str, unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr)
        return;

    if (!root->left && !root->right) {
        huffmanCode[root->char1] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void HuffmanCoding::decode(Node* root, int &index, string str)
{
    if (root == nullptr) {
        return;
    }
    if (!root->left && !root->right)
    {
        cout << root->char1;
        return;
    }
    index++;

    if (str[index] =='0')
        decode(root->left, index, str);
    else
        decode(root->right, index, str);
}
void HuffmanCoding::buildHuffmanTree(string text)
{
    unordered_map<char, int> frequence;
    for (char char1: text) {
        frequence[char1]++;
    }

    priority_queue<Node*, vector<Node*>, compare> pq;

    for (auto pair: frequence) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    while (pq.size() != 1)
    {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top();	pq.pop();

        int sum = left->frequence + right->frequence;
        pq.push(getNode('\0', sum, left, right));
    }
    root = pq.top();
}
void HuffmanCoding::encodeString(string text) {
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    string str = "";
    for (char ch: text) {
        str += huffmanCode[ch];
    }
    cout << "\nEncoded string is :\n" << str << '\n';

}

void HuffmanCoding::decodeString(string decodeString) {
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    int index = -1;
    cout << "\nDecoded string is: \n";
    while (index < (int)decodeString.size() - 2) {
        decode(root, index, decodeString);
    }
}

void HuffmanCoding::executeEncoding(string input_file) {
    encode_file.open(input_file,std::ios::in);
    string line;
    string total="";
    if (encode_file.is_open()){
        while (getline(encode_file,line)){
            line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
            total=total+line+'\n';

        }
        total=total.substr(0,total.length()-1);
        config_file.open("config.txt",std::ios::out);
        config_file<<"true";
        config_file.close();
        tree_file.open("tree.txt",std::ios::out);
        tree_file<<total;
        tree_file.close();
        buildHuffmanTree(total);
        encodeString(total);

    }
    else{
        cout<<"hata";
    }
}

void HuffmanCoding::executeReturn(char *s) {
    ifstream temp;
    temp.open("config.txt",std::ios::in);
    string line;
    if (temp.is_open()){
        while (getline(temp,line)){
            if (line=="true"){
                encode_file.open("tree.txt",std::ios::in);
                string line;
                string total="";
                if (encode_file.is_open()) {
                    while (getline(encode_file, line)) {
                        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
                        total = total + line+'\n';

                    }
                    total=total.substr(0,total.length()-1);

                }
                buildHuffmanTree(total);
                unordered_map<char, string> huffmanCode;
                encode(root, "", huffmanCode);

                cout << "Huffman Codes are :\n" << '\n';
                for (auto pair: huffmanCode) {
                    if (pair.first==s[0]){
                        if (s=="\n"){
                            cout << "\\n"<< " " << pair.second << '\n';

                        }else{
                            cout << pair.first << " " << pair.second << '\n';

                        }
                    }
                }
            }else{
                cout<<"This command must not be performed without encoding operation"<<'\n';
            }
        }
    }else{
        cout<<"hata";
    }
}

void HuffmanCoding::executeDecoding(string input_file) {
    ifstream temp;
    temp.open("config.txt",std::ios::in);
    string line;
    if (temp.is_open()){
        while (getline(temp,line)){
            if (line=="true"){
                encode_file.open("tree.txt",std::ios::in);
                string line;
                string total;
                if (encode_file.is_open()) {
                    while (getline(encode_file, line)) {
                        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
                        total = total + line+'\n';

                    }
                    total=total.substr(0,total.length()-1);
                }
                buildHuffmanTree(total);
                decode_file.open(input_file,std::ios::in);
                if (decode_file.is_open()){
                    while (getline(decode_file,line)){
                        decodeString(line);
                    }
                }
            }else{
                cout<<"This command must not be performed without encoding operation"<<'\n';
            }
        }
    }else{
        cout<<"hata";
    }
}

void HuffmanCoding::executeListing() {
    ifstream temp;
    temp.open("config.txt",std::ios::in);
    string line;
    if (temp.is_open()){
        while (getline(temp,line)){
            if (line=="true"){
                encode_file.open("tree.txt",std::ios::in);
                string line;
                string total;
                if (encode_file.is_open()) {
                    while (getline(encode_file, line)) {
                        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
                        total = total + line+'\n';
                    }
                    total=total.substr(0,total.length()-1);
                }
                buildHuffmanTree(total);
                unordered_map<char, string> huffmanCode;
                encode(root, "", huffmanCode);
                printList(root,0);

            }else{
                cout<<"This command must not be performed without encoding operation"<<'\n';
            }
        }
    }else{
        cout<<"hata";
    }


}
