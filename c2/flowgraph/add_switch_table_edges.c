void __fastcall add_switch_table_edges(c2_function *fn,c2_block *from,c2_switch_case *cases)

{
  if (cases != (c2_switch_case *)0x0) {
    add_switch_table_edges(fn,from,cases->next);
    flow_edge_delete_to(from,(cases->label->u14).block,fn);
    cfg_add_edge(fn,from,(cases->label->u14).block);
  }
  return;
}

