#ifdef IMPL
#define C CHECK_IMPL
#else
#define C CHECK
#endif

C(std::string);
C(std::wstring);
C(std::stringstream);
C(std::istringstream);
C(std::ostringstream);
C(std::pair<int COMMA bool>);
C(std::pair<int COMMA std::pair<bool COMMA char> >);
C(std::vector<bool>);
C(std::vector<bool>::iterator);
C(std::vector<bool>::const_iterator);
C(std::vector<bool>::reverse_iterator);
C(std::vector<bool>::const_reverse_iterator);
C(std::vector<int>);
C(std::vector<int>::iterator);
C(std::vector<int>::const_iterator);
C(std::vector<int>::reverse_iterator);
C(std::vector<int>::const_reverse_iterator);
C(std::deque<int>);
C(std::deque<int>::iterator);
C(std::deque<int>::const_iterator);
C(std::deque<int>::reverse_iterator);
C(std::deque<int>::const_reverse_iterator);
C(std::list<int>);
C(std::list<int>::iterator);
C(std::list<int>::const_iterator);
C(std::list<int>::reverse_iterator);
C(std::list<int>::const_reverse_iterator);
C(std::set<int>);
C(std::set<int>::iterator);
C(std::set<int>::reverse_iterator);
C(std::map<int COMMA char>);
C(std::map<int COMMA char>::iterator);
C(std::map<int COMMA char>::const_iterator);
C(std::multiset<int>);
C(std::multimap<int COMMA char>);
C(std::allocator<int>);
C(std::bitset<10>);
C(std::complex<float>);
C(std::complex<double>);
C(std::complex<long double>);
C(std::fstream);
C(std::ifstream);
C(std::ofstream);
C(std::ios_base::Init);
C(std::exception);
C(std::locale);
C(ioerr);

#ifdef HAS_CODECVT
C(cvt);
#endif

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
C(std::atomic<int>);
C(std::nullptr_t);

#endif

#ifdef HAS_CXX17

C(std::shared_mutex);
C(std::shared_timed_mutex);
C(std::byte);

#endif

#ifdef HAS_FILESYSTEM
C(std::filesystem::path);
C(std::filesystem::file_time_type)
#endif

#ifdef HAS_OPTIONAL
//C(std::optional<int>);
#endif

#ifdef HAS_STRINGVIEW
C(std::string_view);
#endif

#ifdef HAS_ANY
C(std::any)
#endif

#ifdef HAS_VARIANT
C(std::variant<int COMMA char>);
#endif

#ifdef HAS_CXX20

C(std::span<int>);

#endif

#undef C
