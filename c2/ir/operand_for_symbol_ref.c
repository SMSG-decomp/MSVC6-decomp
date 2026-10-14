c2_operand * __fastcall operand_for_symbol_ref(c2_fe_symbol *fs)

{
  uint32_t uVar1;
  uint16_t uVar2;
  c2_symbol *pcVar3;
  c2_operand *pcVar4;
  
  switch(fs->cls) {
  case '\0':
    halt_baddata();
  case '\x01':
    pcVar3 = fe_symbol_get_storage(fs);
    uVar1 = g_symbol_class_address_op[pcVar3->cls];
    pcVar4 = (c2_operand *)node_alloc('\x03');
    uVar2 = g_ptr_type;
    pcVar4->op = uVar1;
    pcVar4->sym = pcVar3;
    pcVar4->type = uVar2;
    return pcVar4;
  }
}

