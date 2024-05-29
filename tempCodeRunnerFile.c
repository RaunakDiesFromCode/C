for (int i = 0; i < size; i++)
    {
        snow[i] = arr[i] + rand() % 3 - 7;
        if (snow[i] < 0)
        {
            snow[i] = 0;
        }
    }