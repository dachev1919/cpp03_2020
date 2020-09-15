for (int i = 0; i < n; i++)
        x[i] = 1;

    cout << "Diogonalnoe preobladanie: " << endl;
    if (diagonal(a, n))
    {
        do
        {
            for (int i = 0; i < n; i++)
                p[i] = x[i];
            for (int i = 0; i < n; i++)
            {
                double var = 0;
                for (int j = 0; j < i; j++)
                    var += (a[i][j] * x[j]);
                for (int j = i + 1; j < n; j++)
                    var += (a[i][j] * p[j]);
                x[i] = (b[i] - var) / a[i][i];
            }
            m++;
        } while (!converge(x, p, n, eps));

        cout << "Reshenie:" << endl
             << endl;
        for (i = 0; i < n; i++)
            cout << "x" << i << " = " << okr(x[i], eps) << "" << endl;
        cout << "Iteraciy: " << m << endl;
    }
    else
    {
        cout << "Ne vipolnyaetsya preobladanie diogonaley" << endl;
    }