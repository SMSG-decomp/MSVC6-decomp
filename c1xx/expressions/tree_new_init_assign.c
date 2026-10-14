c1_node * tree_new_init_assign(c1_node *target,c1_node *value)

{
  c1_node *pcVar1;
  
  pcVar1 = tree_new_binary('t',target,value);
  return pcVar1;
}

