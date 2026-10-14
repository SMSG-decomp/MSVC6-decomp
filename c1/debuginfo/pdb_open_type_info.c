char __fastcall pdb_open_type_info(c1_pdb_state *pdb_state)

{
  PDB *this;
  char *szMode;
  int iVar1;
  char acStack_104 [260];
  
  this = pdb_state->pdb;
  if ((this == (PDB *)0x0) || (pdb_state->tpi == (TPI *)0x0)) {
    szMode = "ri";
    if (pdb_state->read_only == '\0') {
      szMode = "wi";
    }
    iVar1 = (*this->vtbl->OpenTpi)(this,szMode,&pdb_state->tpi);
    if (iVar1 == 0) {
      (*pdb_state->pdb->vtbl->QueryPDBName)(pdb_state->pdb,acStack_104);
      diag_error(0x1d7,acStack_104);
      return '\0';
    }
  }
  return '\x01';
}

