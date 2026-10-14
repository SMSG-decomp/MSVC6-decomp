void __cdecl tree_attach_typed_link(c1_node *n,c1_type *type)

{
  c1_node *pcVar1;
  
  if (n->link == (c1_node *)0x0) {
    pcVar1 = tree_new_node('`',n,(c1_node *)0x0,type);
    n->link = pcVar1;
  }
  return;
}

