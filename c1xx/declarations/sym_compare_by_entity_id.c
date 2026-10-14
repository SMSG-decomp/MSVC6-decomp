int __cdecl sym_compare_by_entity_id(c1_symbol **a,c1_symbol **b)

{
  return ((*a)->entity & 0xffffff) - ((*b)->entity & 0xffffff);
}

