c2_bitset * __fastcall alias_resolve_single_symbol_set(c2_symbol **out_root,uint32_t node)

{
  c2_bitset *pcVar1;
  c2_tuple *pcVar2;
  c2_symbol *pcVar3;
  
  pcVar1 = g_alias_ref_table[node].pointee_nodes;
  if ((((pcVar1 != (c2_bitset *)0x0) &&
       (pcVar2 = g_alias_ref_table[node].def, pcVar2 != (c2_tuple *)0x0)) && (pcVar2->op == 0x15b))
     && ((pcVar2->src->kind == '\x02' && (pcVar3 = pcVar2->src->sym, (pcVar3->flags5 & 8) != 0)))) {
    *out_root = pcVar3;
    return pcVar1;
  }
  return (c2_bitset *)0x0;
}

