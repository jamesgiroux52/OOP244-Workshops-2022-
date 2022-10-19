/*
 ============================================================================
 Name        : Basket.h
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : October 17, 2022 - Workshop 5 - part 2
 ============================================================================
*/
/*
 ============================================================================
 I have done all the coding by myself in this header
 ============================================================================
*/

#ifndef SDDS_BASKET_H_
#define SDDS_BASKET_H_

namespace sdds {
    // fruit details
    struct Fruit {
        char m_name[30 + 1];
        double m_qty;
    };

    // basket of fruit
    class Basket {
        Fruit* m_fruits{};
        int m_numFruits{};
        double m_cost{};
        bool isValid() const;
        void setEmpty();
        void allAndCopy(const Basket& B);
    public:
        Basket();
        Basket(Fruit* frt, int num, double cost);
        Basket(const Basket& B); 
        Basket& operator=(const Basket& B);
        ~Basket();
        void setPrice(double cost);
        operator bool() const;
        Basket& operator+=(Fruit frt);
        std::ostream& display(std::ostream& ostr) const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Basket& basket);
}

#endif // !SDDS_BASKET_H_

