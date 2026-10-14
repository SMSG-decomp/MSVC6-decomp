void __fastcall type_check_array_bound_constant(c1_declarator *d)

{
  byte bVar1;
  byte bVar2;
  c1_type *pcVar3;
  c1_type *pcVar4;
  
  if ((d->kind == 5) || (d->kind == 6)) {
    if (d->type->code == 0x4083) {
      diag_error(0x21c);
    }
    pcVar4 = type_reference_to(d->type,'\x01');
    d->type = pcVar4;
  }
  else if ((d->spec[0] & 7) != 7) {
    pcVar4 = d->type;
    d->flags54 = d->flags54 | 0x80;
    pcVar3 = pcVar4;
    if ((pcVar4->code & 0x8f) == 0x83) {
      do {
        pcVar3 = pcVar3->base;
      } while ((pcVar3->code & 0x8f) == 0x83);
      bVar1 = ~((byte)pcVar3->code >> 7) & 1;
    }
    else {
      bVar1 = 0;
    }
    bVar2 = bVar1 << 1 | d->flags55 & 0xfd;
    bVar1 = d->spec[3];
    d->flags55 = bVar2;
    if ((((bVar1 & 0x80) == 0) && (pcVar4->code != 0x4083)) &&
       ((pcVar4->extra).cls == (c1_symbol *)0x0)) {
      d->flags55 = bVar2 | 1;
      return;
    }
  }
  return;
}

