so my whole understanding with the factory method is that it is a three way relationship between client, factory and product.

so A factory produces products as we all know and the factory only produces when instraucted by the clinet.
so we have to let our client make a request to the factory so it can produce a particular product for us.

benefits:
    the factory method improves flexibility of the code structure. 


Abstract factory is used when we are producing different different objects but they are of related types.

in programming concepts, when we use an enum type of three features say 
white, long, and 2000. and we are creating hundred different products that all share color size and age. we use an abstract factory for all the different objects types and each factory produces objects of a particular enum type.

say one factory can produce only long objects, other factories will produce only white objects.(say white cars, white bicycles, white dogs) etc.

so with my dress and shoe approach. 

the Abstract factory's whole job is to make shoes and dresses. 

and since we have dresses and shoes for church, school, and party, our shoe products and dress products are related by the church, school and party type.

so we create an abstract factory that makes both shoes and dresses. all other factories to inherit from it must produce both shoes and dresses but those of a particular type.

so one factory will produce only church dresses and shoes. the other factory will produce only school dresses and shoes, and the last factory will produce only party dresses and shoes.

clients/ customers to use our products come for products. they don't come for the types but rather products. so our customers are of two classes of shoe and dresses. when a customer requesting for shoe, we get the type he /she wants and we get for them.