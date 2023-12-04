struct film {
        char title[100];
        int year;
        int length;
        char country[100];
        char genre[100];
        char director[100];
        int rank;
};
void write(struct film * arr, int n);
void read(struct film **arr, int *n);
void create(struct film **arr, int *n);
void search(struct film* arr, int n);
