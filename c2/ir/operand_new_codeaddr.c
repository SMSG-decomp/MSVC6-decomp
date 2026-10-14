c2_operand * __fastcall operand_new_codeaddr(uint32_t op,void *sym)

{
  uint16_t uVar1;
  c2_operand *pcVar2;
  
  pcVar2 = (c2_operand *)node_alloc('\x04');
  uVar1 = g_ptr_type;
  pcVar2->op = op;
  pcVar2->sym = sym;
  pcVar2->type = uVar1;
  return pcVar2;
}

