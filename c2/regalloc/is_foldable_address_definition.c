int __fastcall is_foldable_address_definition(c2_tuple *t)

{
  uint8_t uVar1;
  c2_operand *pcVar2;
  uint32_t uVar3;
  
  if (t->dst->next != (c2_operand *)0x0) {
    return 0;
  }
  if (t->op != 0x12) {
    return 0;
  }
  pcVar2 = t->src;
  if (pcVar2->kind != '\x05') {
    return 0;
  }
  uVar3 = pcVar2->op;
  if (uVar3 == 0x14c) {
    uVar1 = ((pcVar2->base->u18).reg)->cls;
  }
  else if (uVar3 == 0x14f) {
    if (g_opt_favor_speed == 0) {
      return 0;
    }
    uVar1 = ((pcVar2->index->u18).reg)->cls;
  }
  else {
    if (uVar3 != 0x14d) {
      return 0;
    }
    if (g_opt_favor_speed == 0) {
      return 0;
    }
    if (((pcVar2->base->u18).reg)->cls != '\x02') {
      return 0;
    }
    uVar1 = ((pcVar2->index->u18).reg)->cls;
  }
  if (uVar1 != '\x02') {
    return 0;
  }
  return 1;
}

