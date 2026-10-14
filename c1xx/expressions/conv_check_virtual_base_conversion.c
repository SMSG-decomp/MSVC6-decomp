c1_node * __cdecl conv_check_virtual_base_conversion(c1_conversion *conv)

{
  char cVar1;
  c1_type *pcVar2;
  c1_symbol *pcVar3;
  c1_symbol *pcVar4;
  
  pcVar2 = conv->target;
  cVar1 = (char)pcVar2->code;
  while (cVar1 < '\0') {
    pcVar2 = pcVar2->base;
    cVar1 = (char)pcVar2->code;
  }
  if ((pcVar2->code & 0x300) == 0) {
    pcVar3 = (c1_symbol *)0x0;
  }
  else {
    pcVar3 = (pcVar2->extra).cls;
  }
  pcVar2 = conv->source;
  cVar1 = (char)pcVar2->code;
  while (cVar1 < '\0') {
    pcVar2 = pcVar2->base;
    cVar1 = (char)pcVar2->code;
  }
  if ((pcVar2->code & 0x300) == 0) {
    pcVar4 = (c1_symbol *)0x0;
  }
  else {
    pcVar4 = (pcVar2->extra).cls;
  }
  diag_error(0x27b,pcVar4,pcVar3);
  return conv->expr;
}

