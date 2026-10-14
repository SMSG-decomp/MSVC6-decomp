c1_tag_symbol * __cdecl class_check_tag_kind_consistency(c1_tag_symbol *tag,short kind)

{
  char cVar1;
  c1_type *pcVar2;
  c1_type *pcVar3;
  
  pcVar2 = tag->type;
  cVar1 = (char)pcVar2->code;
  pcVar3 = pcVar2;
  while (cVar1 < '\0') {
    pcVar3 = pcVar3->base;
    cVar1 = (char)pcVar3->code;
  }
  if (pcVar3->code != kind) {
    diag_error(0xb,tag,pcVar2);
    tag->flags2 = tag->flags2 | 1;
  }
  return tag;
}

