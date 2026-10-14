c2_tuple * __fastcall rmw_fold_negated_add(c2_tuple *t)

{
  c2_operand *old;
  c2_tuple *pcVar1;
  int iVar2;
  
  old = t->src->next;
  if (((1 << (old->kind & 0x1f) & 6U) != 0) && (pcVar1 = old->sym->def, pcVar1 != (c2_tuple *)0x0))
  {
    pcVar1 = simplify_tuple_tree(pcVar1);
    if ((t->op == 0x16d) && (pcVar1->op == 0x161)) {
      iVar2 = types_compatible(old->type,pcVar1->type);
      if (iVar2 != 0) {
        tuple_replace_src(t,old,pcVar1->src);
        tuple_unlink_free(pcVar1);
        t->op = 0x16e;
      }
    }
  }
  return t;
}

