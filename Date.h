class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date();
    Date(int d, int m, int y);

    int get_day() const;
    int get_month() const;
    int get_year() const;

    void set_day(int d);
    void set_month(int m);
    void set_year(int y);

    Date &operator++();
    Date operator++(int);
    Date &operator--();
    Date operator--(int);
    Date operator+(int days) const;
    Date operator-(int days) const;
    Date &operator+=(int days);
    Date &operator-=(int days);
    bool operator<(const Date &other) const;
    bool operator>(const Date &other) const;
    bool operator<=(const Date &other) const;
    bool operator>=(const Date &other) const;
    bool operator==(const Date &other) const;
    bool operator!=(const Date &other) const;
};
