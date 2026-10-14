c2_factor_term * __fastcall factor_find_term_entry(c2_node *node)

{
  int iVar1;
  c2_factor_term *pcVar2;
  
  pcVar2 = g_factor_terms[node->rank_or_prev >> 8 & 0xf ^ node->rank_or_prev & 0xf];
  while( true ) {
    iVar1 = compare_trees(node,pcVar2->tree);
    if (iVar1 == 0) break;
    pcVar2 = pcVar2->next;
  }
  return pcVar2;
}

