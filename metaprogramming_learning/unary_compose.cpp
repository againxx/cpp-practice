template<typename Operation1, typename Operation2>
class unary_compose {
protected:
    Operation1 op1;
    Operation2 op2;
public:
    unary_compose(const Operation1& x, const Operation2& y) : op1(x), op2(y) {}
    typename Operation1::result_type
    operator() (const typename Operation2::argument_type& x) const {
        return op1(op2(x));
    }
};

template<typename Operation1, typename Operation2>
inline unary_compose<Operation1, Operation2> compose1(const Operation1& op1, const Operation2& op2) {
    return unary_compose<Operation1, Operation2>(op1, op2);
}
