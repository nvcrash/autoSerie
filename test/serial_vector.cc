#include <autoSerie/serial.hh>
#include <vector>

int main()
{
  {
    std::cerr << A().a << std::endl;
    std::vector<int> a;
    std::vector<int> b;
    for (int i = 0; i < 2050; i++)
    {
      a.push_back(i);
      b.push_back(i + 2050);
    }

    std::stringstream ss;
    autoSerie::serial::write(ss, a);
    std::stringstream ss2(ss.str());
    autoSerie::serial::read(ss2, b);
    for (int i = 0; i < 2050; i++)
    {
      assert(b.at(i) == a.at(i));
    }
  }

  {
    std::vector<bool> a;
    std::vector<bool> b;

    for (int i = 0; i < 50; i++)
    {
      a.push_back(i % 2);
      b.push_back((i + 1) % 2);
    }

    std::stringstream ss;
    autoSerie::serial::write(ss, a);
    if (ss.fail())
    {
      std::cerr << "write error" << std::endl;
    }
    std::stringstream ss2(ss.str());
    autoSerie::serial::read(ss2, b);
    if (ss.fail())
    {
      std::cerr << "read error" << std::endl;
    }
    for (int i = 0; i < 50; i++)
    {
      if (b.at(i) != a.at(i))
      {
	std::cerr << "[" << i << "] "
		<< b.at(i) << " shall be " << a.at(i);
	assert(b.at(i) == a.at(i));
      }
    }
  }
  return 0;

}
