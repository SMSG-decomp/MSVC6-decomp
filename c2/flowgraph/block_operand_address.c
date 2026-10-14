c2_node * __fastcall block_operand_address(int unused,c2_operand *opnd,int unused2)

{
  c2_node *pcVar1;
  c2_operand *pcVar2;
  
  if (opnd->kind != '\x02') {
    pcVar1 = node_clone((c2_node *)opnd->base);
    return pcVar1;
  }
  pcVar2 = operand_new_symaddr(opnd->op,opnd->sym);
  return (c2_node *)pcVar2;
}

