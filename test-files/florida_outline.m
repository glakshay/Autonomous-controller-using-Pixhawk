function florida_outline (  )

%*****************************************************************************80
%
%% FLORIDA_OUTLINE displays an outline map of Florida.
%
%  Discussion:
%
%    This program is similar to an example from the MATLAB Mapping 
%    Toolbox User's Guide.
%
%  Licensing:
%
%    This code is distributed under the GNU LGPL license.
%
%  Modified:
%
%    23 June 2016
%
  fprintf ( 1, '\n' );
  fprintf ( 1, 'FLORIDA_OUTLINE:\n' );
  fprintf ( 1, '  MATLAB version\n' );
  fprintf ( 1, '  Display an outline map of Florida.\n' );

  figure
%
%  Construct a map axis suitable for displaying Florida.
%
  ax = usamap ( 'Florida' );
%
%  SHAPEREAD() reads the shapes of the US states.
%  We will use the "low resolution" data.
%  We will ask for "geo coords", that is, longitude and latitude.
%  Because of our bounding box, only Florida will be set up.
%
%  By the way, for no discernible or sensible reason, the following command
%  will not be be understood if I write "strcmpi (" instead of "strcmpi(".
%  A language in which spacing between tokens matters?  Just that one particular
%  space?  Please explain!  No, please don't!.
%
  florida_lo = shaperead ( 'usastatelo', ...
    'UseGeoCoords', true,...
    'Selector', { @ ( name ) strcmpi( name, 'Florida' ), 'Name' } );
%
%  Display the outline, and fill with a green with some blue.
%
  geoshow ( florida_lo, 'FaceColor', [ 0.3, 1.0, 0.675 ] );
%
%  Print the label "Florida".
%
  textm ( florida_lo.LabelLat, florida_lo.LabelLon, ...
    florida_lo.Name, 'HorizontalAlignment', 'center' );
%
%  Save a copy of the plot.
%
  print ( '-dpng', 'florida_outline.png' )

  return
end