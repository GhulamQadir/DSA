#include <iostream>
using namespace std;

// Node structure representing a single page in browser history
struct Node
{
    Node *backward; // Pointer to the previous page (Back button)
    Node *forward;  // Pointer to the next page (Forward button)
    string url;     // The URL of the page
};

// Global pointer to track the page currently being viewed
Node *current = nullptr;

// Initializes the browser history with a homepage.
void initialize(string url)
{
    current = new Node();
    current->url = url;
    current->backward = nullptr;
    current->forward = nullptr;
}

// * Visits a new URL. This clears all existing forward history.
void visit(string url)
{
    Node *new_node = new Node();
    new_node->url = url;
    new_node->forward = nullptr;

    // If browser was never initialized (safety check)
    if (current == nullptr)
    {
        new_node->backward = nullptr;
        current = new_node;
        return;
    }

    // IMPORTANT: Clear all forward history before adding a new page
    // If you were at 'abc.com' -> 'google.com' and you visit 'fb.com',
    // 'google.com' must be deleted from history.
    Node *temp = current->forward;
    while (temp != nullptr)
    {
        Node *temp1 = temp;
        temp = temp->forward;
        delete temp1; // Freeing memory of unreachable forward pages
    }

    // Linking the new page to the current history
    new_node->backward = current; // New page points back to current
    current->forward = new_node;  // Current page points forward to new page
    current = new_node;           // Move the 'current' view to the new page
}

// Moves forward in history by 'count' steps.
string forward(int count)
{
    int i = 0;

    // Move forward as long as there are forward pages AND we haven't reached count
    while (current->forward != nullptr && i < count)
    {
        current = current->forward;
        i++;
    }
    return current->url; // Return the URL we landed on
}

// Moves backward in history by 'count' steps.
string backward(int count)
{
    int i = 0;
    // Move backward as long as there are previous pages AND we haven't reached count
    while (current->backward != nullptr && i < count)
    {
        current = current->backward;
        i++;
    }
    return current->url; // Return the URL we landed on
}

int main()
{
    // Start with homepage
    initialize("abc.com");

    // Visit some pages
    visit("youtube.com");
    visit("news.com");

    // Test Backward: Going back 2 steps from news.com should take us to abc.com
    string url = backward(2);
    cout << "Backward 2 steps: " << url << endl;

    // Test Forward: Trying to go 6 steps (will stop at news.com as it's the latest)
    url = forward(6);
    cout << "Backward 6 steps: " << url << endl;

    // Visiting a new page now will clear any forward history if it existed
    visit("facebook.com");
    visit("karachi.com");

    cout << "Current url: " << current->url << endl;
}