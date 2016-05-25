/*
* Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>
*
* Everyone is permitted to copy and distribute verbatim copies
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef EXECUTE_HH
# define EXECUTE_HH
# include <tuple>

namespace autoSerie
{
  namespace util
  {

    namespace
    {
      template<int ...> struct seq {};
      template<int N, int ...S> struct gens : gens<N-1, N-1, S...> {};
      template<int ...S> struct gens<0, S...>{ typedef seq<S...> type; };
    }
    template <typename ReturnType, typename ...Args>
    class Call
    {

    public:
      ReturnType execute(std::tuple<Args...> params)
      {
	return callFunc(params, typename gens<sizeof...(Args)>::type());
      }
      typedef std::tuple<Args...> t_args;

    protected:
      // to set in the inherited constructor
      ReturnType (*func)(Args...);

      // execute the call

      template<int ...S>
      ReturnType callFunc(std::tuple<Args...> params, seq<S...>)
      {
	return func(std::get<S>(params) ...);
      }


    };
  }
}
#endif /* EXECUTE_HH */
