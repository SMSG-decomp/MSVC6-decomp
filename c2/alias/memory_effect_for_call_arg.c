c2_operand * __fastcall memory_effect_for_call_arg(c2_operand *op,void *a,uint32_t cls,int d)

{
  uint8_t uVar1;
  uint32_t uVar2;
  c2_operand *pcVar3;
  
  pcVar3 = op->sym->def->src;
  uVar1 = pcVar3->kind;
  if (uVar1 != '\x03') {
    if ((uVar1 != '\x02') && (uVar1 != '\x01')) {
      pcVar3 = operand_new_memeffect(cls);
      return pcVar3;
    }
    if (g_opt_assume_no_alias == 0) {
      uVar2 = alias_class_for_memory_base(pcVar3->sym,a,cls,(c2_block *)d);
      pcVar3 = operand_new_memeffect(uVar2);
      return pcVar3;
    }
    uVar2 = alias_class_for_operand(pcVar3,a,cls);
    pcVar3 = operand_new_memeffect(uVar2);
    return pcVar3;
  }
  if ((((g_opt_bzalign != 0) && (uVar1 = pcVar3->sym->cls, uVar1 != '\x03')) && (uVar1 != '\x04'))
     && ((uVar1 != '\x05' && (uVar1 != '\x06')))) {
    pcVar3 = operand_new_memeffect(3);
    return pcVar3;
  }
  pcVar3 = operand_new_memeffect((uint)(pcVar3->sym->storage->fe->u3e).alias_class);
  return pcVar3;
}

