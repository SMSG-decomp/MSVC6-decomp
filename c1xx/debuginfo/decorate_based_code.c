byte * __cdecl decorate_based_code(byte *out,byte flags,c1_symbol *base_sym)

{
  c1_type *type;
  c1_u16 cVar1;
  byte *pbVar2;
  char *pcVar3;
  
  cVar1 = (c1_u16)flags;
  if ((flags & 0x18) == 8) {
    *out = 0x30;
    return out + 1;
  }
  type = base_sym->type;
  if ((char)type->code < '\0') {
    cVar1 = type->flags;
  }
  if ((cVar1 & 8) != 0) {
    *out = 0x35;
    pbVar2 = (byte *)decorate_name_with_backreference((char *)(out + 1),(int)base_sym->name,0);
    pbVar2 = decorate_type_text(pbVar2,type);
    pcVar3 = decorate_scope_chain((char *)pbVar2,&base_sym->kind);
    *pcVar3 = '@';
    return (byte *)(pcVar3 + 1);
  }
  *out = 0x32;
  pcVar3 = decorate_name_with_backreference((char *)(out + 1),(int)base_sym->name,0);
  pcVar3 = decorate_scope_chain(pcVar3,&base_sym->kind);
  *pcVar3 = '@';
  return (byte *)(pcVar3 + 1);
}

