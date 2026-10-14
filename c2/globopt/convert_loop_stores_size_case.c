c2_operand * __fastcall convert_loop_stores_size_case(int k,c2_tuple *t)

{
  switch(k) {
  case 1:
    return t->src->sym->def->src;
  case 2:
    return t->src->next->sym->def->src;
  case 3:
    return t->src->next->next->sym->def->src;
  case 4:
    return t->src->next->next->next->sym->def->src;
  }
}

