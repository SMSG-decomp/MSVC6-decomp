int __fastcall substitution_allowed(c2_symbol *s,int kind,int uses)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 1;
  if ((1 < uses) ||
     ((((s->cls == '\x01' && (kind == 1)) && (uVar1 = s->storage->id, 5 < uVar1)) && (uVar1 < 9))))
  {
    iVar2 = 0;
  }
  return iVar2;
}

