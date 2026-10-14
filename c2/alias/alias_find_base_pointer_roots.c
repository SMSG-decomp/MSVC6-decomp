int __fastcall
alias_find_base_pointer_roots
          (c2_symbol *base_temp,c2_bitset *mask,c2_symbol **out_root,c2_bitset **out_set)

{
  byte bVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  c2_symbol *sym;
  c2_bitset *src;
  int iVar4;
  int local_8;
  
  pcVar2 = base_temp->def;
  local_8 = 0;
  if (pcVar2->op == 0x17d) {
    return 0;
  }
  if ((pcVar2->kind == '\x0e') || (pcVar2->kind == '\x12')) {
    return -1;
  }
  pcVar3 = pcVar2->src;
  do {
    if (pcVar3 == (c2_operand *)0x0) {
      return local_8;
    }
    bVar1 = pcVar3->kind;
    if (bVar1 != 0) {
      if (bVar1 < 3) {
        if ((pcVar3->flags & 0x20) == 0) {
          if (((1 << (bVar1 & 0x1f) & 6U) == 0) || (pcVar3->sym->def == (c2_tuple *)0x0)) {
            sym = pcVar3->sym;
            if ((sym->flags5 & 8) == 0) goto LAB_1072c337;
            src = symbol_overlap_alias_set(sym,mask);
            if (*out_set == (c2_bitset *)0x0) {
              *out_set = src;
            }
            else {
              bitset_or(*out_set,src);
              bitset_free(src);
            }
            if (local_8 != -1) {
              local_8 = local_8 + 1;
            }
            *out_root = sym;
          }
          else {
            iVar4 = alias_find_base_pointer_roots(pcVar3->sym,mask,out_root,out_set);
            if (iVar4 == -1) {
              local_8 = -1;
            }
            else if (local_8 != -1) {
              local_8 = local_8 + iVar4;
            }
          }
        }
      }
      else if (bVar1 == 6) {
LAB_1072c337:
        local_8 = -1;
      }
    }
    pcVar3 = pcVar3->next;
  } while( true );
}

