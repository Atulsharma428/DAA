#include <iostream>
using namespace std;

int weight(int source, int destination, int **distance)
{
  return distance[source][destination];
}

int ShortestPathLength(int source, string arr, int **distance, int t = 0)
{
  if (1 == arr.size() - t)
  {
    return weight(source, 0, distance);
  }

  int min = INT_MAX;
  for (int i = t; i < arr.size(); i++)
  {
    if (i == source)
    {
      continue;
    }
    int temp = weight(source, i, distance) + ShortestPathLength(i, arr, distance, t + 1);
    if (temp < min)
    {
      min = temp;
    }
  }
  return min;
}
int main()
{
  string arr;
  cout << "Enter the cities to visit(including the base city)(string input): ";
  cin >> arr;

  int n = arr.size();
  int **distance = new int *[n];
  for (int i = 0; i < n; i++)
  {
    distance[i] = new int[n];
  }

  cout << "Enter the distance between each city: " << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << "City " << i << " to City " << j << ": ";
      if (i == j)
      {
        cout << "For Same city the distance is automatically set to 0" << endl;
        distance[i][j] = 0;
        continue;
      }
      cin >> distance[i][j];
    }
  }

  int answer = ShortestPathLength(0, arr, distance);
  cout << "The minimum distance to cover all the above cities is " << answer << endl;
  return 0;
}