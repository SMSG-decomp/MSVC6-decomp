c2_tuple * __fastcall distribute_before_final(c2_tuple *t,c2_tuple *parent)

{
  c2_tuple *local_4;
  
  local_4 = t;
  if (t->op == 0x16d) {
    t = hoist_common_negation(t,parent,0x161);
  }
  else if ((t->op == 0x177) && (t->src->op == 0x172)) {
    distribute_constant_over_op(&local_4,0x172,parent);
    return local_4;
  }
  return t;
}

