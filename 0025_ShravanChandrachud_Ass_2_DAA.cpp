#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct MinHeapNode
{
    char data;
    int freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, int freq)
    {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

void printCodes(struct MinHeapNode *root, string str, unordered_map<char, string> &huffmanCodes)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->data != '$')
    {
        cout << root->data << ": " << str << endl;
        huffmanCodes[root->data] = str;
    }
    printCodes(root->left, str + "0", huffmanCodes);
    printCodes(root->right, str + "1", huffmanCodes);
}

struct compare
{
    bool operator()(MinHeapNode *a, MinHeapNode *b)
    {
        return (a->freq > b->freq);
    }
};

MinHeapNode *HuffmanCode(char data[], int freq[], int size, unordered_map<char, string> &huffmanCodes)
{
    struct MinHeapNode *left, *right, *temp;

    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;

    for (int i = 0; i < size; i++)
    {
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    }

    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();

        temp = new MinHeapNode('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;

        minHeap.push(temp);
    }

    printCodes(minHeap.top(), "", huffmanCodes);

    return minHeap.top();
}

string encode(const string &text, unordered_map<char, string> &huffmanCodes)
{
    string encodedString = "";
    for (char ch : text)
    {
        encodedString += huffmanCodes[ch];
    }
    return encodedString;
}

string decode(const string &encodedString, MinHeapNode *root)
{
    string decodedString = "";
    MinHeapNode *current = root;

    for (char bit : encodedString)
    {
        if (bit == '0')
            current = current->left;
        else
            current = current->right;

        if (!current->left && !current->right)
        {
            decodedString += current->data;
            current = root;
        }
    }

    return decodedString;
}

int main()
{
    // Input characters and their frequencies
    char data[] = {'A', 'B', 'C', 'D'};
    int freq[] = {2, 1, 3, 4};
    int size = 4;

    unordered_map<char, string> huffmanCodes;

    MinHeapNode *root = HuffmanCode(data, freq, size, huffmanCodes);

    string text = "";

    cin >> text;

    string encodedString = encode(text, huffmanCodes);
    cout << "\nEncoded string: " << encodedString << endl;

    string decodedString = decode(encodedString, root);
    cout << "Decoded string: " << decodedString << endl;

    return 0;
}
