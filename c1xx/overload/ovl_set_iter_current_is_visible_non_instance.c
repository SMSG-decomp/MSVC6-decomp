char __fastcall ovl_set_iter_current_is_visible_non_instance(c1xx_ovl_set_iter *iter)

{
  c1_sym_link *pcVar1;
  
  pcVar1 = iter->current;
  if ((pcVar1[-1].position & 0x1f) != 0x1a) {
    return (char)(((byte)~*(byte *)((int)&pcVar1[2].type + 1) & 0x40) >> 6);
  }
  if ((((pcVar1->type).alias)->hidden == '\0') &&
     ((*(byte *)((int)&((pcVar1->type).alias)->target->tail + 9) & 0x40) == 0)) {
    return '\x01';
  }
  return '\0';
}

