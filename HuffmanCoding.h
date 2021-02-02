//
// Created by Ates on 12/23/2020.
//

#ifndef ASSIGNMENT4_HUFFMANCODING_H
#define ASSIGNMENT4_HUFFMANCODING_H
#include <fstream>
#include <string>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Node
{
    char char1;
    int frequence;
    Node *left, *right;
};
struct compare
{
    bool operator()(Node* l, Node* r)
    {
        // highest priority item has lowest frequency
        return l->frequence > r->frequence;
    }
};


class HuffmanCoding{

    public:
    ifstream encode_file;
    ofstream tree_file;
    ofstream config_file;
    ifstream decode_file;

    Node* root;
    Node* getNode(char ch, int freq, Node* left, Node* right);

    HuffmanCoding();

    void encode(Node* root, string str, unordered_map<char, string> &huffmanCode);
    void decode(Node* root, int &index, string str);
    void buildHuffmanTree(string text);

    void encodeString(string text);
    void decodeString(string decodeString);

    void executeEncoding(string input_file);
    void executeReturn(char *s);
    void executeDecoding(string input_file);
    void executeListing();
    void printList(Node* root,int space);
};


#endif //ASSIGNMENT4_HUFFMANCODING_H
