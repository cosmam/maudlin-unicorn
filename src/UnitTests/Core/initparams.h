#ifndef INITPARAMS_T_H
#define INITPARAMS_T_H

#include <QVariant>
#include <memory>

namespace Test
{
    class InitParams
    {
    public:
        InitParams();

        ~InitParams();

        InitParams( const InitParams &rhs );
        InitParams &operator=( const InitParams &rhs );

        InitParams( InitParams &&rhs );
        InitParams &operator=( InitParams &&rhs );

        void insertValue( QString key, QVariant value );

        QVariant value( const QString &key ) const;

        bool contains( const QString &key ) const;

    private:
        class Impl;
        std::unique_ptr<Impl> m_Impl;
    };

    template <class T> T getValue( const InitParams & params, const QString & key, const T & fallback )
    {
        auto value = params.value(key);
        if( value.isValid() && value.canConvert<T>() ) {
            return value.value<T>();
        }
        return fallback;
    }

    template <class T> T getValue( const InitParams & params, const QString & key )
    {
        return getValue<T>(params, key, T());
    }
}

#endif // INITPARAMS_T_H
