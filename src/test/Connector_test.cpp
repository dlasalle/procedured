/**
* @file Connector_test.cpp
* @brief Unit tests for the Connector class.
* @author Dominique LaSalle <dominique@solidlake.com>
* Copyright 2018
* @version 1
* @date 2018-08-23
*/


#include "UnitTest.hpp"
#include "Connector.hpp"

namespace procedured
{

UNITTEST(Connector, Null)
{
  Connector conn;

  testTrue(conn.is_null());
}

UNITTEST(Connector, Type)
{
  Connector conn(5);

  testEqual(conn.type(), 5);
}

UNITTEST(Connector, Accepts)
{
  Connector conn(5);
  conn.add_reciever(3);
  conn.add_reciever(2);
  conn.add_reciever(4);

  testFalse(conn.accepts(0));
  testFalse(conn.accepts(1));
  testTrue(conn.accepts(2));
  testTrue(conn.accepts(3));
  testTrue(conn.accepts(4));
  testFalse(conn.accepts(5));
}

}
