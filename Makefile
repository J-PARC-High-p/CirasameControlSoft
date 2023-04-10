all:
	$(MAKE)	-C CoreLib/src;
	$(MAKE)	-C Common/src;
	$(MAKE)	-C Skelton/src;
#	$(MAKE)	-C HRM/src;
#	$(MAKE)	-C Scaler/src;
#	$(MAKE)	-C MHTDC/src;
#	$(MAKE)	-C HRTDC/src;

clean:
	$(MAKE)	-C CoreLib/src clean;
	$(MAKE)	-C Common/src clean;
	$(MAKE)	-C Skelton/src clean;
#	$(MAKE)	-C HRM/src clean;
#	$(MAKE)	-C Scaler/src clean;
#	$(MAKE)	-C MHTDC/src clean;
#	$(MAKE)	-C HRTDC/src clean;
