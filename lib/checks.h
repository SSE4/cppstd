#ifdef IMPL
#define C CHECK_IMPL
#else
#define C CHECK
#endif

C(std::string);
C(std::stringstream);
C(std::pair<int COMMA bool>);
C(std::vector<bool>);
C(std::vector<int>);
C(std::deque<int>);
C(std::list<int>);
C(std::set<int>);
C(std::map<int COMMA char>);
C(std::multiset<int>);
C(std::multimap<int COMMA char>);

#ifdef HAS_CXX11

C(std::tuple<int>);
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

#endif

#ifdef HAS_CXX17

C(std::string_view);
C(std::optional<int>);
C(std::any);
C(std::variant<int>);
C(std::shared_mutex);
C(std::shared_timed_mutex);
//C(std::filesystem::path);
C(std::byte);

#endif

#ifdef HAS_CXX20

C(std::span<int>);

#endif

#undef C
