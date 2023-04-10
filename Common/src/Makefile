BINDIR		= ../bin
DATADIR		= ../data
CXXFLAGS	+= -Wall -g -MMD -std=c++1y

CORELIB_DIR	= ../../CoreLib
CXXFLAGS 	+= -I. -I$(CORELIB_DIR)/src
LDFLAGS		+= -L$(CORELIB_DIR)/lib -lhul

SRCALL		= $(wildcard *.cc)
DEPENDS		= $(SRCALL:.cc=.d)

SRC		= $(filter-out %main.cc,$(SRCALL))
OBJ		= $(SRC:.cc=.o)

TARGET 		= reconfig_fpga mcs_converter flash_memory_programmer read_xadc read_sem inject_sem_error erase_eeprom reset_sem check_spi_device verify_mcs set_cdce62002 set_sitcpreg set_ctrl_eeprom set_max1932 read_ad9220 set_hgddelay

echo		:= /bin/echo -e
mkdir		:= mkdir -p

.PRECIOUS: %.o

all: $(TARGET)

%: %_main.o $(OBJ)
	@if [ ! -d $(BINDIR) ]; then \
	  $(echo) "mkdir -p $(BINDIR)"; $(mkdir) $(BINDIR); \
	fi
	$(CXX) -o $(BINDIR)/$@ $< $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(BINDIR)/* *.o *.d *~

show:
	@ $(echo) "CXXFLAGS = $(CXXFLAGS)"
	@ $(echo) "LDFLAGS  = $(LDFLAGS)"
	@ $(echo) "SRCALL   = $(SRCALL)"
	@ $(echo) "DEPENDS  = $(DEPENDS)"
	@ $(echo) "SRC      = $(SRC)"
	@ $(echo) "OBJ      = $(OBJ)"

-include $(DEPENDS)
