c1_symbol * __cdecl
tmpl_find_overload_by_signature(c1_symbol *set,c1_symbol *member,c1_arg_list *inst_args)

{
  fe_name **ppfVar1;
  byte bVar2;
  c1_symbol *sym;
  c1_symbol *pcVar3;
  c1_symbol *pcVar4;
  int deduction_ctx [12];
  
  ppfVar1 = &set->name;
  pcVar4 = (c1_symbol *)0x0;
  if ((((ppfVar1 != (fe_name **)0x0) &&
       (bVar2 = set->kind & 0x1f, pcVar4 = (c1_symbol *)ppfVar1, bVar2 != 7)) && (bVar2 != 8)) &&
     ((bVar2 != 6 && ((set->kind & 0x1f) != 0x1a)))) {
    pcVar4 = (c1_symbol *)set->type;
  }
  do {
    pcVar3 = pcVar4;
    if ((ppfVar1 == (fe_name **)0x0) || (pcVar3 == (c1_symbol *)0x0)) {
      return (c1_symbol *)0x0;
    }
    bVar2 = set->kind & 0x1f;
    if ((((bVar2 == 7) || (bVar2 == 8)) || (bVar2 == 6)) || ((set->kind & 0x1f) == 0x1a)) {
      pcVar4 = (c1_symbol *)0x0;
    }
    else {
      pcVar4 = *(c1_symbol **)&pcVar3->flags4;
    }
    sym = (c1_symbol *)((int)&pcVar3[-1].tail + 4);
    if ((*(byte *)((int)&pcVar3[-1].tail + 4) & 0x1f) == 0x1a) {
      sym = *(c1_symbol **)pcVar3->next;
    }
    tmpl_deduction_begin((c1_tmpl_deduction *)deduction_ctx,sym,inst_args,1,'\0');
    bVar2 = tmpl_compare_argument_lists((c1_tmpl_deduction *)deduction_ctx,member);
  } while (bVar2 == 0);
  if ((*(byte *)((int)&pcVar3[-1].tail + 4) & 0x1f) != 0x1a) {
    return (c1_symbol *)((int)&pcVar3[-1].tail + 4);
  }
  return *(c1_symbol **)pcVar3->next;
}

