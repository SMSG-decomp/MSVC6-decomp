int __fastcall disp_within_symbol(c2_symbol *sym,int disp)

{
  return (uint)(sym->storage->offset <= sym->offset + disp);
}

