void __fastcall cxx_eh_copy_object_record(c2_node *node,c2_node *node2)

{
  c2_eh_state *pcVar1;
  
  pcVar1 = cxx_eh_clone_object_record((c2_eh_state *)(node[2].next)->op);
  (node2[2].next)->op = (uint32_t)pcVar1;
  return;
}

