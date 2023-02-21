#include <bits/stdc++.h>
#include <boost/bimap.hpp>

namespace FlyweightPre
{
    class Font
    {
    private:
        std::string keyword;

    public:
        Font(const std::string &key)
        {
            std::cout << key << std::endl;
        }
    };
}

namespace Flyweight
{
    class FontFactory // 字体工厂
    {
    private:
        std::unordered_map<std::string, FlyweightPre::Font *> fontPool;

    public:
        FlyweightPre::Font *GetFont(const std::string &key)
        {
            if (fontPool.count(key) != 0)
            {
                return fontPool[key];
            }
            else
            {
                auto font = new FlyweightPre::Font(key);
                fontPool[key] = font;
                return font;
            }
        }
    };

    // 另一种场景的享元模式
    struct User
    {
        using key = uint32_t;
        User(const std::string &first_name, const std::string &last_name) : first_name{add(first_name)}, last_name{add(last_name)}
        {
        }

    protected:
        key first_name, last_name;
        static boost::bimap<key, std::string> names; // boost库中的双向映射
        static key seed;
        static key add(const std::string &s);
    };

    User::key User::add(const std::string &s)
    {
        auto it = names.right.find(s);
        if (it == names.right.end())
        {
            names.insert({++seed, s});
            return seed;
        }
        return it->second;
    }

    User::key User::seed = 0;
    boost::bimap<User::key, std::string> User::names;
}

int main()
{

    return 0;
}