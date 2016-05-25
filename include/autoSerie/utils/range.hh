#ifndef RANGE_HH
# define RANGE_HH

namespace autoSerie
{
  namespace util
  {
    template<class collection>
    class Range
    {
    private:
      const typename collection::iterator& begin_;
      const typename collection::iterator& end_;
    public:
      Range(const typename collection::iterator& begin__, const typename collection::iterator& end__)
	: begin_(begin__)
	, end_(end__)
      {}
      const typename collection::iterator& begin() {return begin_;}
      const typename collection::iterator& end()   {return end_;}
    };

    template<class collection>
    class constRange
    {
    private:
      const typename collection::const_iterator& cbegin_;
      const typename collection::const_iterator& cend_;
    public:
      constRange(const typename collection::const_iterator& cbegin__, const typename collection::const_iterator& cend__)
	: cbegin_(cbegin__)
	, cend_(cend__)
      {}
      const typename collection::const_iterator& cbegin() const {return cbegin_;}
      const typename collection::const_iterator& cend() const   {return cend_;}
    };
  }
}
#endif /* !RANGE_HH */
