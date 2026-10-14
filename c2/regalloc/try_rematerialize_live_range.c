int __fastcall try_rematerialize_live_range(c2_live_range *range)

{
  c2_tuple *def;
  c2_symbol *sym;
  c2_bitset *bs;
  c2_operand *pcVar1;
  int iVar2;
  int local_8;
  int local_4;
  
  def = (range->u38).def;
  bs = collect_remat_dependencies(def,(c2_live_range *)0x0,&local_8);
  if (bs == (c2_bitset *)0x0) {
    return 0;
  }
  if (local_8 == 0) {
    pcVar1 = def->src;
    iVar2 = 0;
    if (pcVar1 != (c2_operand *)0x0) {
      do {
        if ((pcVar1->kind == '\x01') &&
           (((pcVar1->u18).range)->colour == (c2_register_descriptor *)0x0)) {
          iVar2 = iVar2 + 1;
        }
        pcVar1 = pcVar1->next;
      } while (pcVar1 != (c2_operand *)0x0);
      if (1 < iVar2) {
        bitset_free(bs);
        return 0;
      }
    }
  }
  sym = range->sym;
  local_4 = spill_reload_cost(sym);
  iVar2 = load_saving(sym);
  iVar2 = can_rematerialize_address(def,range,bs,local_4 + iVar2);
  if (iVar2 != 0) {
    substitute_definition_into_uses(def,range,(c2_operand *)0x0);
    free_live_range(range,1);
    bitset_free(bs);
    return 1;
  }
  bitset_free(bs);
  return 0;
}

