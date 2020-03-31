#ifdef IMPL
#define C CHECK_IMPL
#else
#define C CHECK
#endif

C(std::string);
C(std::stringstream);
C(std::pair<int COMMA bool>);
C(std::pair<int COMMA std::pair<bool COMMA char> >);
C(std::vector<bool>);
C(std::vector<int>);
C(std::deque<int>);
C(std::list<int>);
C(std::set<int>);
C(std::map<int COMMA char>);
C(std::multiset<int>);
C(std::multimap<int COMMA char>);
C(std::allocator<int>);

#ifdef HAS_CXX11

C(std::tuple<int COMMA char>);
C(std::tuple<int COMMA std::tuple<bool COMMA char> >);
C(std::mutex);
C(std::recursive_mutex);
C(std::condition_variable);
C(std::condition_variable_any);
C(std::unordered_set<int>);
C(std::unordered_map<int COMMA char>);
C(std::unordered_multiset<int>);
C(std::unordered_multimap<int COMMA char>);
C(std::regex)
C(std::shared_ptr<int>);
C(std::unique_ptr<int>);
C(std::array<int COMMA 10>);
C(std::chrono::time_point<std::chrono::steady_clock>);
C(std::function<void(int)>);

#endif

#ifdef HAS_CXX17

C(std::string_view);
C(std::optional<int>);
C(std::any);
C(std::variant<int COMMA char>);
C(std::shared_mutex);
C(std::shared_timed_mutex);
//C(std::filesystem::path);
C(std::byte);

#endif

#ifdef HAS_CXX20

C(std::span<int>);

#endif

#undef C
