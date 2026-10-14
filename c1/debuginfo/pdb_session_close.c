void __fastcall pdb_session_close(c1_pdb_state *session)

{
  TPI *this;
  NameMap *this_00;
  PDB *this_01;
  
  this = session->tpi;
  if (this != (TPI *)0x0) {
    (*this->vtbl->Close)(this);
    session->tpi = (TPI *)0x0;
  }
  this_00 = session->name_map;
  if (this_00 != (NameMap *)0x0) {
    (*this_00->vtbl->close)(this_00);
    session->name_map = (NameMap *)0x0;
  }
  this_01 = session->pdb;
  if (this_01 != (PDB *)0x0) {
    (*this_01->vtbl->Close)(this_01);
    session->pdb = (PDB *)0x0;
  }
  return;
}

