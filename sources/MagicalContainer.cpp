#include "MagicalContainer.hpp"
#include <algorithm>

using namespace std;
using namespace ariel;

    void MagicalContainer::addElement(int obj)
    {
        auto it = std::lower_bound(this->myObj.begin(), this->myObj.end(), obj);
        this->myObj.insert(it, obj);  
        auto Pit = std::lower_bound(this->myPrimeObj.begin(), this->myPrimeObj.end(), obj);
        if(isPrime(obj))
        {
            this->myPrimeObj.insert(Pit, obj);    
        }  
    }

    void MagicalContainer::removeElement(int obj)
    {
        auto it = std::find(this->myObj.begin(), this->myObj.end(), obj);
        if (it != this->myObj.end()) 
        {
            this->myObj.erase(it);
        }
        else
        {
            throw std::runtime_error("");
        }
        auto Pit = std::find(this->myPrimeObj.begin(), this->myPrimeObj.end(), obj);
        if(isPrime(obj))
        {
            this->myPrimeObj.erase(Pit);    
        }  
    }

    bool MagicalContainer::isPrime(int num)
    {
        if (num <= 1) 
        {
            return false;
        }
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    //--------------AscendingIterator---------------

        //move assignment operator
        MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(AscendingIterator &&other) noexcept
        {
            if (this != &other)
            {
                this->myContainer = other.myContainer;
                this->index = other.index;
                other.myContainer = nullptr;
                other.index = 0;
            }
            return *this;
        }

        // Destructor
        MagicalContainer::AscendingIterator::~AscendingIterator(){}

        // Assignment operator
        MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
        {
            if(this->myContainer != other.myContainer)
            {
                throw std::runtime_error("");
            }
            if (this != &other)
            {
                myContainer = other.myContainer;
                index = other.index;
            }
            return *this;
        }

        // Equality comparison (operator==)
        bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const 
        {
            return this->myContainer->myObj[index] == other.myContainer->myObj[index];
        }

        // Inequality comparison (operator!=)
        bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const 
        {
            return !(*this == other);
        }

        // GT, LT comparison (operator>, operatorn<)
        bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other)
        {
            return this->myContainer->myObj[index] > other.myContainer->myObj[index];
        }

        bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other)
        {
            return this->myContainer->myObj[index] < other.myContainer->myObj[index];
        }

        // Dereference operator (operator*)
        int MagicalContainer::AscendingIterator::operator*()
        {
            return this->myContainer->myObj[index];
        }

        // Pre-increment operator (operator++) ++i
        MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++()
        {
            if(this->index == this->myContainer->size() - 1)
            {
                throw std::runtime_error("");
            }
            this->index++;
            return *this;
        }

        // begin(type)
        MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
        {
            return AscendingIterator(*myContainer);
        }

        // end(type)
        MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
        {
            AscendingIterator it(*myContainer);
            it.index = myContainer->myObj.size();  // Set index to the size of the set
            return it;
        }

    
    //--------------SideCrossIterator---------------

        //move assignment operator
        MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(SideCrossIterator &&other) noexcept
        {
            if (this != &other)
            {
                this->myContainer = other.myContainer;
                this->index = other.index;
                other.myContainer = nullptr;
                other.index = 0;
            }
            return *this;
        }

        // Destructor
        MagicalContainer::SideCrossIterator::~SideCrossIterator(){}

        // Assignment operator
        MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
        {
            if(this->myContainer != other.myContainer)
            {
                throw std::runtime_error("");
            }
            if (this != &other)
            {
                myContainer = other.myContainer;
                index = other.index;
            }
            return *this;
        }

        // Equality comparison (operator==)
        bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const 
        {
            return this->myContainer->myObj[index] == other.myContainer->myObj[index];
        }

        // Inequality comparison (operator!=)
        bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const 
        {
            return !(*this == other);
        }

        // GT, LT comparison (operator>, operatorn<)
        bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other)
        {
            return this->myContainer->myObj[index] > other.myContainer->myObj[index];
        }

        bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other)
        {
            return this->myContainer->myObj[index] < other.myContainer->myObj[index];
        }

        // Dereference operator (operator*)
        int MagicalContainer::SideCrossIterator::operator*()
        {
            return this->myContainer->myObj[index];
        }

        // Pre-increment operator (operator++) ++i
        MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator++()
        {
            if(index == (this->myContainer->size() / 2))
            {
                throw std::runtime_error("");
            }
            if(this->index > (this->myContainer->size() / 2))
            {
                this->index = static_cast<vector<int>::size_type>(this->myContainer->size() - static_cast<int>(this->index));
            }
            else
            {
                this->index = static_cast<vector<int>::size_type>((this->myContainer->size() - 1) - static_cast<int>(this->index));
            }
            return *this;
        }   

        // begin(type)
        MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
        {
            return SideCrossIterator(*myContainer);
        }

        // end(type)
        MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
        {
            SideCrossIterator it(*myContainer);
            it.index = myContainer->myObj.size() / 2;  // Set index to the size of the set
            return it;
        }

    
    //--------------PrimeIterator---------------

        //move assignment operator
        MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(PrimeIterator &&other) noexcept
        {
            if (this != &other)
            {
                this->myContainer = other.myContainer;
                this->index = other.index;
                other.myContainer = nullptr;
                other.index = 0;
            }
            return *this;
        }

        // Destructor
        MagicalContainer::PrimeIterator::~PrimeIterator(){}

        // Assignment operator
        MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
        {
            if(this->myContainer != other.myContainer)
            {
                throw std::runtime_error("");
            }
            if (this != &other)
            {
                myContainer = other.myContainer;
                index = other.index;
            }
            return *this;
        }

        // Equality comparison (operator==)
        bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const 
        {
            return this->myContainer->myObj[index] == other.myContainer->myObj[index];
        }

        // Inequality comparison (operator!=)
        bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const 
        {
            return !(*this == other);
        }

        // GT, LT comparison (operator>, operatorn<)
        bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other)
        {
            return this->myContainer->myObj[index] > other.myContainer->myObj[index];
        }

        bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other)
        {
            return this->myContainer->myObj[index] < other.myContainer->myObj[index];
        }

        // Dereference operator (operator*)
        int MagicalContainer::PrimeIterator::operator*()
        {
            return this->myContainer->myPrimeObj[index];
        }

        // Pre-increment operator (operator++) ++i
        MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator++()
        {
            if(this->index == (this->myContainer->myPrimeObj.size()))
            {
                throw std::runtime_error("");
            }
            this->index++;
            return *this;
        }

        // begin(type)
        MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
        {
            return PrimeIterator(*myContainer);
        }

        // end(type)
        MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
        {
            PrimeIterator it(*myContainer);
            it.index = myContainer->myObj.size();  // Set index to the size of the set
            return it;
        }



